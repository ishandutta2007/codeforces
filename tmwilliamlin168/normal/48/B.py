n, m = map(int, input().split())
x = [list(map(int, input().split())) for i in range(n)]
a, b = map(int, input().split())
def solve(n, m, x):
    y = [[0]*(m+1) for i in range(n+1)]
    for i in range(n):
        for j in range(m):
            y[i+1][j+1]=y[i+1][j]+x[i][j]
        for j in range(m):
            y[i+1][j+1]+=y[i][j+1]
    ans = n*m
    for i in range(a, n+1):
        for j in range(b, m+1):
            ans = min(ans, y[i][j]-y[i-a][j]-y[i][j-b]+y[i-a][j-b])
    return ans
print(min(solve(n, m, x), solve(m, n, list(map(list, zip(*x))))))