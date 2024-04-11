#include<bits/stdc++.h>
using namespace std;

char s[1000007];
char ans[1007][1007];
int cnt[1007];
int n,l,k;
vector<int> vec(26,0);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>l>>k;
    cin>>s;
    for (int i=0;i<n*l;++i){
        vec[s[i]-'a']++;
    }
    int left=0;
    for (int i=0;i<26;++i){
        int j=left;
        while (vec[i]&&cnt[j]<l){
            ans[j][cnt[j]++]=i+'a';
            j++;
            if (j>=k) j=left;
            vec[i]--;
        }
        left=j;
        if (cnt[j]==l) break;
    }
    int fk=0;
    for (int i=0;i<n;++i){
        for (int j=0;j<l;++j){
            while (fk<26&&vec[fk]==0) fk++;
            if (!ans[i][j]) ans[i][j]=fk+'a', vec[fk]--;
        }
    }
    for (int i=0;i<n;++i){
        for (int j=0;j<l;++j){
            cout<<ans[i][j];
        }
        cout<<"\n";
    }
    return 0;
}