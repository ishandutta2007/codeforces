#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int game[100000];
vector<int> first;
vector<int> second;
vector<pair<int,int> > ans;

int main() {
    scanf("%d",&n);
    first.clear();
    second.clear();
    for (int i=0;i<n;i++) {
        scanf("%d",&game[i]);
        if (game[i]==1) first.push_back(i);
        else second.push_back(i);
    }
    int mustWin = game[n-1];
    for (int t=1;t<=n;t++) {
        int firstWon = 0;
        int secondWon = 0;
        int firstStart = -1;
        int secondStart = -1;
        while (true) {
            if (first.size()>firstStart+t && second.size()>secondStart+t) {
                if (first[firstStart+t]<second[secondStart+t]) {
                    firstWon+=1;
                    firstStart+=t;
                    secondStart = upper_bound(second.begin(),second.end(),first[firstStart])-second.begin()-1;
                } else {
                    secondWon+=1;
                    secondStart+=t;
                    firstStart = upper_bound(first.begin(),first.end(),second[secondStart])-first.begin()-1;
                }
            } else if (first.size()>firstStart+t) {
                firstWon+=1;
                firstStart+=t;
                secondStart = upper_bound(second.begin(),second.end(),first[firstStart])-second.begin()-1;
            } else if (second.size()>secondStart+t) {
                secondWon+=1;
                secondStart+=t;
                firstStart = upper_bound(first.begin(),first.end(),second[secondStart])-first.begin()-1;
            } else {
                if (firstStart==first.size()-1 && secondStart==second.size()-1) {
                    if ((firstWon>secondWon && mustWin==1) || (firstWon<secondWon && mustWin==2)) {
                        ans.push_back(make_pair(max(firstWon,secondWon),t));
                    }
                }
                break;
            }
        }
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for (int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);

    return 0;
}