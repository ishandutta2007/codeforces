#include<bits/stdc++.h>

const int N = 300010;
typedef std::pair <int, int> pii;

std::vector <bool> vec[N];
pii p[N];
int sit[N];

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    int cnt = 0, left = 0, t3 = 0;
    for (int i = 0; i < q; ++ i){
        int type;
        scanf("%d", &type);
        if (type == 1){
            int x;
            scanf("%d", &x);
            vec[x].push_back(false);
            p[cnt ++] = {x, vec[x].size() - 1};
            ++ left;
        }
        else if (type == 2){
            int x;
            scanf("%d", &x);
            while (sit[x] < vec[x].size()){
                vec[x][sit[x] ++] = true;
                -- left;
            }
        }
        else{
            int t;
            scanf("%d", &t);
            while (t3 < t){
                if (!vec[p[t3].first][p[t3].second]){
                    vec[p[t3].first][p[t3].second] = true;
                    ++ sit[p[t3].first];
                    -- left;
                }
                ++ t3;
            }
        }
        printf("%d\n", left);
    }
    return 0;
}