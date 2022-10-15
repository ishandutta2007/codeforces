#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char *argv[])
{
    int t; cin >> t;
    for (int k = 0; k < t; ++k)
    {
        int n; cin >> n;

        priority_queue<int> q;
        int num_bad = 0;

        for (int i = 0; i < n; ++i)
        {
            int a; cin >> a;
            while (!q.empty() && q.top() > a)
            {
                num_bad += 1;
                q.pop();
            }
            q.push(a);
        }
        cout << num_bad << endl;
    }
    return 0;
}