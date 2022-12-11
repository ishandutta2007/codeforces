#include <bits/stdc++.h>

using namespace std;

/*
const int M = (int)2e8 + 10;
char buf[M];
int mpos = 0;

void* operator new(size_t size) {
    mpos += size;
    return buf + mpos - size;
}

void operator delete(void*) {}
*/

using ll = long long;

struct Segment {
    int l, r;
    ll sum;
    Segment() : l(), r(), sum() {}
    Segment(int _l, int _r, ll _sum) : l(_l), r(_r), sum(_sum) {}
};

using SegmentsPair = pair<int, int>;

queue<SegmentsPair> pairs;

struct Node {
    int l, r;
    Segment segment;
    Node() : l(), r(), segment() {}
    Node(int _l, int _r, Segment _segment) : l(_l), r(_r), segment(_segment) {}
    bool IsValid() const {
        return l != -1 && r != -1;
    }
};

const int N = (int)3e6 + 10;
Node nodes[N];
bool erased[N];
int nodes_it = 0;

ll GetDelta(const SegmentsPair &a) {
    return nodes[a.first].segment.sum * (nodes[a.second].segment.r - nodes[a.second].segment.l + 1) - 
           nodes[a.second].segment.sum * (nodes[a.first].segment.r - nodes[a.first].segment.l + 1);
}

int Insert(int id, Segment value) {
    auto new_it = nodes_it++;
    auto prev_id = nodes[id].l;
    nodes[prev_id].r = new_it;
    nodes[id].l = new_it;
    nodes[new_it] = Node(prev_id, id, value);
    return new_it;
}

void Erase(int id) {
    auto prev_id = nodes[id].l;
    auto next_id = nodes[id].r;
    nodes[prev_id].r = next_id;
    nodes[next_id].l = prev_id;
    erased[id] = true;
}

int main() {
    int n;
    scanf("%d", &n);
    nodes[nodes_it++] = Node(-1, 1, Segment());
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        nodes[nodes_it] = Node(nodes_it - 1, nodes_it + 1, Segment(i, i, x));
        nodes_it++;

        if (i > 0) {
            auto pair = make_pair(i, i + 1);
            if (GetDelta(pair) > 0) {
                pairs.push(pair);
            }
        }
    }
    nodes[nodes_it] = Node(nodes_it - 1, -1, Segment());
    nodes_it++;
    
    while (pairs.size() > 0) {
        SegmentsPair it = pairs.front();
        auto first = it.first;
        auto second = it.second;
        pairs.pop();
        if (erased[first] || erased[second]) {
            continue;
        }
        auto delta = GetDelta(it);
        if (delta <= 0) {
            throw logic_error("WTF?");
        }
        int l = nodes[first].segment.l;
        int r = nodes[second].segment.r;
        auto sum = nodes[first].segment.sum + nodes[second].segment.sum;
        auto new_segment = Segment(l, r, sum);

        auto new_it = Insert(second, new_segment);

        if (nodes[nodes[first].l].IsValid()) {
            auto prev_first = nodes[first].l;
            auto new_pair = make_pair(prev_first, new_it);
            if (GetDelta(new_pair) > 0) {
                pairs.push(new_pair);
            }
        }
        if (nodes[nodes[second].r].IsValid()) {
            auto next_second = nodes[second].r;
            auto new_pair = make_pair(new_it, next_second);
            if (GetDelta(new_pair) > 0) {
                pairs.push(new_pair);
            }
        }

        Erase(first);
        Erase(second);
    }

    for (int ptr = nodes[0].r; nodes[ptr].r != -1; ptr = nodes[ptr].r) {
        double value = nodes[ptr].segment.sum * 1.0 / (nodes[ptr].segment.r - nodes[ptr].segment.l + 1);
        for (int i = nodes[ptr].segment.l; i <= nodes[ptr].segment.r; i++) {
            printf("%.9lf\n", value);
        }
    }

    return 0;
}