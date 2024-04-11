#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;scanf("%i %i %i",&n,&m,&k);
    for(int i=0,x,y;i<k;i++)scanf("%i %i",&x,&y);
    for(int i=0,x,y;i<k;i++)scanf("%i %i",&x,&y);
    vector<char> ans;
    for(int i=0;i<n-1;i++)ans.push_back('U');
    for(int i=0;i<m-1;i++)ans.push_back('L');
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==n-1&&j==m-1)continue;
            if(j==m-1)ans.push_back('D');
            else{
                if(i%2==0)ans.push_back('R');
                else ans.push_back('L');
            }
        }
    }
    printf("%i\n",(int)ans.size());
    for(char c:ans)printf("%c",c);
    return 0;
}