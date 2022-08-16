n = int(input())
ans = 0
a = []
for i in range(n):
    a.append(input())
for i in range(1,n-1):
    for j in range(1,n-1):
        if a[i][j] == a[i-1][j-1] == a[i-1][j+1] == a[i+1][j-1] == a[i+1][j+1] == 'X':
            ans += 1
print(ans)