#include<cstdio>
#include<algorithm>
#include<vector>
struct s{
    int v, i;
    bool operator<(const s &A) const{return v>A.v;}
} d[300001];
int du(int x, int y){
    return x/y + (x%y==0?0:1);
}
int chk[300001];
int main(){
    int n, x1, x2;
    scanf("%d%d%d", &n, &x1, &x2);
    for(int i=1; i<=n; i++){
        scanf("%d", &d[i].v);
        d[i].i = i;
    } 
    std::sort(d+1, d+n+1);
    int max = 0, t, maxK;
    for(int i=n; i>=1; i--){
        t = i - du(x2, d[i].v);
        if(max < t){
            max = t;
            maxK = i;
        }
        t = du(x1, d[i].v); 
        if(t <= max && t <= i){
            printf("Yes\n");
            printf("%d %d\n", t, du(x2, d[maxK].v));
            for(int j=0; j<t; j++){
                chk[i-j] = 1;
                printf("%d ", d[i-j].i);
            }
            printf("\n");
            t = du(x2, d[maxK].v);
            for(int j=0; j<t; j++, maxK--){
                if(chk[maxK] == 1) {
                    j--; continue;
                }
                printf("%d ", d[maxK].i);
            }
            printf("\n");
            return 0;
        }
    }

    max = 0;
    for(int i=n; i>=1; i--){
        t = i - du(x1, d[i].v);
        if(max < t){
            max = t;
            maxK = i;
        }
        t = du(x2, d[i].v); 
        if(t <= max && t <= i){
            printf("Yes\n");
            printf("%d %d\n", du(x1, d[maxK].v), t);
            std::vector<int> tmp;
            for(int j=0; j<t; j++){
                chk[i-j] = 1;
                tmp.push_back(d[i-j].i);
            }
            t = du(x1, d[maxK].v);
            for(int j=0; j<t; j++, maxK--){
                if(chk[maxK] == 1) {
                    j--; continue;
                }
                printf("%d ", d[maxK].i);
            }
            printf("\n");
            for(auto t: tmp) printf("%d ", t);
            printf("\n");
            return 0;
        }
    }

    printf("No\n");
    return 0;
}