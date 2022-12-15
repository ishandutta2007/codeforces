#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int psa[MN][3], n, i, x, y, a[3];
string s;

int main(){
    cin >> s >> n;
    for(i=1;i<=s.size();i++){
        for(int j=0;j<3;j++){
            psa[i][j] = psa[i-1][j];
        }
        if(s[i-1]=='x') psa[i][0] ++;
        else if(s[i-1]=='y') psa[i][1] ++;
        else psa[i][2] ++;
    }
    for(;n;n--){
        scanf("%d%d",&x,&y);
        for(int i=0;i<3;i++)
            a[i] = psa[y][i]-psa[x-1][i];
        if(y-x+1<3) printf("YES\n");
        else{
            sort(a,a+3);
            if(a[2]-a[0]>1) printf("NO\n");
            else printf("YES\n");
        }
    }
    return 0;
}