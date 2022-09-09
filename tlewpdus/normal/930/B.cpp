#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n;
char str[5100];
vector<int> st[30];
int chk[30];
double res;

int main() {
    int i;

    scanf("%s",str);
    n = strlen(str);
    for (i=0;i<n;i++) st[str[i]-'a'].push_back(i);
    for (i=0;i<26;i++) {
        int maxi = 0;
        for (int j=1;j<n;j++) {
            memset(chk,0,sizeof(chk));
            for (int k=0;k<st[i].size();k++) {
                chk[str[(st[i][k]+j)%n]-'a']++;
            }
            int cnt = 0;
            for (int k=0;k<26;k++) cnt += (chk[k]==1);
            maxi = max(maxi,cnt);
        }
        res += 1.0*maxi/n;
    }
    printf("%.12f\n",res);

    return 0;
}