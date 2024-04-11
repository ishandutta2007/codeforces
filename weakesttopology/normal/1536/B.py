from string import ascii_lowercase
from itertools import product
t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    def check(k):
        S = set()
        for i in range(n - k + 1):
            S.add(s[i:i + k])
        return len(S) == 26 ** k
    k = 1
    while check(k):
        k += 1
    S = set()
    for i in range(n - k + 1):
        S.add(s[i:i + k])
    ans = None
    for t in product(ascii_lowercase, repeat=k):
        t = ''.join(t)
        if t not in S:
            ans = t
            break
    print(ans)