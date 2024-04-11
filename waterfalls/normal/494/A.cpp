#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    char s[100005];
    scanf("%s",&s);
    int len = strlen(s);
    int last = -1;
    for (int i=0;i<len;i++) if (s[i]=='#') last = i;
    int diff = 0;
    int ones = 0;
    int lastVal = 0;
    bool ok = true;
    for (int i=0;i<len;i++) {
        if (s[i]=='(') diff+=1;
        if (s[i]==')') diff-=1;
        if (s[i]=='#' && i!=last) {
            diff-=1;
            ones+=1;
        }
        if (s[i]=='#' && i==last) {
            int after = 0;
            for (int j=len-1;j>i;j--) {
                if (s[j]=='(') after+=1;
                if (s[j]==')') after-=1;
                if (after>0) ok = false;
            }
            lastVal = diff+after;
            if (lastVal<=0) ok = false;
            diff = 0;
            break;
        }
        if (diff<0) {
            ok = false;
            break;
        }
    }
    if (ok && diff==0) {
        for (int i=0;i<ones;i++) printf("1\n");
        if (last!=-1) printf("%d\n",lastVal);
    } else printf("-1");

    return 0;
}