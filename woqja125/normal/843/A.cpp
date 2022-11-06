#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
pair<int, int> a[100001];
vector<vector<int>> ans;
int v[100001];
int main(){
        int n;
        scanf("%d", &n);
        for(int i=1; i<=n; i++){
                scanf("%d", &a[i].first);
                a[i].second = i;
        }
        sort(a+1, a+n+1);
        for(int i=1; i<=n; i++){
                int x = i;
                if(v[i] == 1) continue;
                ans.push_back(vector<int>());
                do{
                        ans.back().push_back(x);
                        v[x] = 1;
                        x = a[x].second;
                }while(x!=i);
        }
        printf("%d\n", (int)ans.size());
        for(auto &v: ans){
                sort(v.begin(), v.end());
                printf("%d ", (int)v.size());
                for(auto &x: v) printf("%d ", x);
                printf("\n");
        }
        return 0;
}