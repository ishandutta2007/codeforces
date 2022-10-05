#include <bits/stdc++.h>

const int N = 1 << 17;
const int BLOCK = 1304;
const int BLOCK1 = 1 << 11;
const int BLOCK_NUM = 110;

struct Item{
    int id, pos;
};

int b[N];
int l[N], r[N], block_id[N];
std::vector <Item> vec[BLOCK_NUM][BLOCK1 << 1];
int right_bound[BLOCK_NUM][BLOCK1 << 1];

std::vector <Item> merge(std::vector <Item> vec1, const std::vector <Item> &vec2, int r_bound){
    if (vec2.empty()){
        return vec1;
    }
    int sz1 = vec1.size(), sz2 = vec2.size();
    for (int i = 0, j = 0; i < sz1; ++ i){
        while (j < sz2 && vec2[j].pos - j - 1 < vec1[i].pos){
            ++ j;
        }
        if (j < sz2){
            int cur = vec2[j].pos, num = cur - j - 1;
            vec1[i].pos = cur - 1 - (num - vec1[i].pos);
        }
        else{
            int cur = r_bound + 1, num = r_bound - int(vec2.size());
            vec1[i].pos = cur - 1 - (num - vec1[i].pos);
        }
    }
    std::vector <Item> result;
    for (int i = 0, j = 0; i < sz1 || j < sz2; ){
        if (j == sz2 || (i < sz1 && vec1[i].pos < vec2[j].pos)){
            result.push_back(vec1[i ++]);
        }
        else{
            result.push_back(vec2[j ++]);
        }
    }
    return result;
}

int query_pos(int prev_pos, int bid){
    auto &vector = vec[bid][1];
    int left = 0, right = vector.size();
    while (left < right){
        int mid = (left + right) / 2;
        int num = vector[mid].pos - mid - 1;
        if (num < prev_pos){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    if (left < int(vector.size())){
        int cur = vector[left].pos, num = cur - left - 1;
        return cur - 1 - (num - prev_pos);
    }
    int cur = r[bid] + 1, num = r[bid] - int(vector.size());
    return cur - 1 - (num - prev_pos);
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &b[i]);
    }
    int block_num = 0;
    memset(l, 0x3f, sizeof(l));
    for (int i = 1; i <= n; ++ i){
        int bid;
        bid = block_id[i] = i / BLOCK;
        l[bid] = std::min(l[bid], i);
        r[bid] = std::max(r[bid], i);
        block_num = std::max(block_num, bid + 1);
    }
    for (int i = 0; i < block_num; ++ i){
        for (int j = l[i]; j <= r[i]; ++ j){
            vec[i][j - l[i] + BLOCK1] = {Item{j, j - b[j]}};
            right_bound[i][j - l[i] + BLOCK1] = j;
        }
        for (int j = BLOCK1 - 1; j; -- j){
            vec[i][j] = merge(vec[i][j << 1], vec[i][j << 1 | 1], right_bound[i][j << 1 | 1]);
            right_bound[i][j] = vec[i][j << 1 | 1].empty() ? right_bound[i][j << 1] : right_bound[i][j << 1 | 1];
        }
    }
    int test;
    scanf("%d", &test);
    while (test --){
        int type;
        scanf("%d", &type);
        if (type == 1){
            int pos, val;
            scanf("%d%d", &pos, &val);
            b[pos] = val;
            int bid = block_id[pos];
            int seg_pos = pos - l[bid] + BLOCK1;
            vec[bid][seg_pos] = {Item{pos, pos - val}};
            for (seg_pos >>= 1; seg_pos; seg_pos >>= 1){
                vec[bid][seg_pos] = merge(vec[bid][seg_pos << 1], vec[bid][seg_pos << 1 | 1], right_bound[bid][seg_pos << 1 | 1]);
            }
        }
        else{
            int pos;
            scanf("%d", &pos);
            int bid = block_id[pos];
            int cur = -1;
            for (auto item : vec[bid][1]){
                if (pos == item.id){
                    cur = item.pos;
                    break;
                }
            }
            for (int i = bid; i < block_num - 1; ++ i){
                cur = query_pos(cur, i + 1);
            }
            printf("%d\n", cur);
        }
    }
    return 0;
}