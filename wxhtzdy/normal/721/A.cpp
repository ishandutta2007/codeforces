#include <bits/stdc++.h>
using namespace std;
const int N=150;
char s[N];
int main(){
    int n;scanf("%i",&n);
    scanf("%s",s);
    vector<int> ans;
    for(int i=0;i<n;i++)if(s[i]=='B'){
        int j=i;
        while(i<n&&s[i]==s[j])i++;
        ans.push_back(i-j);
    }
    printf("%i\n",(int)ans.size());
    for(int j:ans)printf("%i ",j);
    return 0;
}