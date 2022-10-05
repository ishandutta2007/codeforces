#include <bits/stdc++.h>
using namespace std;
int n,t;
string s1,s2,s3;
bool f[100005];
int same,diff;
char find(char x,char y){
    if(x!='a'&&y!='a') return 'a';
    if(x!='b'&&y!='b') return 'b';
    if(x!='c'&&y!='c') return 'c';
}
int main(){
    cin>>n>>t;
	t=n-t;
    cin>>s1>>s2;
    for(int i=0;i<n;i++) s3+='0';
    int diff=0;
    for(int i=0;i<n;i++){
        if(s1[i]!=s2[i]) diff++;
        if(s1[i]==s2[i] && t>0){
            s3[i]=s1[i];
            t--;
        }
    }
    if(t>0){
        if(2*t>diff) s3="-1";
        else{
            int cnt=0;
            for(int i=0;i<n;i++){
                if(s3[i]!='0') continue;
                s3[i]=s1[i], cnt++;
                if(cnt==t) break;
            }
            cnt=0;
            for(int i=0;i<n;i++){
                if(s3[i]!='0') continue;
                s3[i]=s2[i], cnt++;
                if(cnt==t) break;
        	}
            for(int i=0;i<n;i++){
                if(s3[i]!='0') continue;
                s3[i]=find(s1[i],s2[i]);
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
            if(s3[i]!='0') continue;
            s3[i]=find(s1[i],s2[i]);
        }
    }
    cout<<s3<<endl;
}