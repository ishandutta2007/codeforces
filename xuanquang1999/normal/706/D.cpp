//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 200005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int q;

struct node {
    int end_count;
    int prefix_count;
    struct node* child[2];
} *head;

void init() {
    head = new node();
    head->prefix_count = 0;
    head->end_count = 0;
}

void _insert(int x) {
    node *current = head;
    current->prefix_count++;
    //debug(x);
    fdto(i, 29, 0) {
        int b = (x>>i)&1;
//        printf("%d %d\n", i, b);
        if (current->child[b] == NULL) {
            current->child[b] = new node();
        }
        current->child[b]->prefix_count++;
        current = current->child[b];
    }
    current->end_count++;
}

void _delete(node *current, int i, int x) {
    current->prefix_count--;

    if (i == -1) {
        current->end_count--;
        return;
    }

    int b = (x>>i)&1;
    _delete(current->child[b], i-1, x);

    if (current->child[b]->prefix_count == 0) {
        current->child[b] = NULL;
    }
}

int query(node *current, int i, int x) {
    if (i == -1) return 0;
    int b = ((x>>i)&1)^1;

    if (current->child[b] != NULL) return query(current->child[b], i-1, x)+(1<<i);
    else return query(current->child[1^b], i-1, x);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    init();
    _insert(0);
    scanf("%d", &q);
    fto(i, 1, q) {
        //debug(i);
        int x;
        char s[2];
        scanf("%s%d", s, &x);
        if (s[0] == '+') {
            _insert(x);
        }
        else if (s[0] == '-') {
            _delete(head, 29, x);
        }
        else if (s[0] == '?') {
            printf("%d\n", query(head, 29, x));
        }
    }

    return 0;
}