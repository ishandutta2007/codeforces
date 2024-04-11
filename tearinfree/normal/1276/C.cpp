#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int n,arr[400000];
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",arr+i);

    sort(arr,arr+n);

    vector<pii> ca;
    for(int i=0,j=0;i<n;i=j) {
        for(j=i;j<n&&arr[i]==arr[j];j++);
        ca.push_back({j-i, arr[i]});
    }
    
    sort(ca.begin(),ca.end());

    int r=1,c=1,sum=n,idx=-1;
    for(int y=n,i=ca.size()-1;y;y--) {
        while(i>=0 && ca[i].first >= y) sum -= ca[i--].first;
        int x = sum / y + (ca.size() - i - 1);
        if(x >= y && r*c < x*y) r=y, c=x, idx=i;
    }

    printf("%d\n%d %d\n",r*c,r,c);
    if(r==1 && c==1) printf("%d\n",arr[0]);
    else {
        vector<vector<int>> ans(r, vector<int>(c, 0));
        for(int j=idx+1;j<ca.size();j++) {
            for(int i=0;i<r;i++) {
                int y=i, x=(j-idx-1+i)%c;
                ans[y][x] = ca[j].second;
            }
        }
        int k=0;
        for(int j=0;j<c;j++) for(int i=0;i<r;i++) {
            int y=i,x=(j+i)%c;
            if(!ans[y][x]) {
                ans[y][x] = ca[k].second;
                ca[k].first--;
                if(!ca[k].first) k++;
            }
        }
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) printf("%d ",ans[i][j]);
            puts("");
        }
    }
    
    return 0;
}