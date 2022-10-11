#include <iostream>
#include <map>
#include <set>
#include <utility>

typedef std::pair<int, int> ii;

ii a[200200];
int freq[400400];

int main()
{
    int n;
    std::cin >> n;
    std::set<int> hmm;
    std::map<int, int> dude;
    for(int i = 0; i < n; i++)
    {
        std::cin >> a[i].first >> a[i].second;
        hmm.insert(a[i].first);
        hmm.insert(a[i].second);
    }
    int c = 1;
    for(auto a : hmm)
        dude[a] = c++;
    for(int i = 0; i < n; i++)
    {
        a[i].first = dude[a[i].first];
        a[i].second = dude[a[i].second];
        freq[a[i].first]++;
        freq[a[i].second + 1]--;
    }
    bool ans = true;
    for(int i = 1; i < 400400; i++)
    {
        freq[i] += freq[i - 1];
        ans = ans && freq[i] <= 2;
    }
    if(ans)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
}