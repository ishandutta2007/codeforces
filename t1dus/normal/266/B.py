n,t = map(int,input().split())
s = list(input())
for j in range(t):
    i = 0
    while i < n-1:
        if s[i] == 'B' and s[i+1] == 'G':
            s[i] = 'G'
            s[i+1] = 'B'
            i += 1
        i += 1
print("".join(s))