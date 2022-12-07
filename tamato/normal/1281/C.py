import sys

input = sys.stdin.readline

mod = 10 ** 9 + 7
t = int(input())
for _ in range(t):
    x = int(input())
    s = input().rstrip('\n')

    X = []
    for i, si in enumerate(s):
        if i == x:
            break
        X.append(int(s[i]))
    ans = len(s)
    for i in range(x):
        ans = (ans + (ans - i - 1) * (X[i] - 1)) % mod
        if len(X) < x:
            if X[i] == 1:
                continue
            X_ = X[i + 1:]
            for j in range(X[i] - 1):
                if len(X) < x:
                    X.extend(X_)
    print(ans)