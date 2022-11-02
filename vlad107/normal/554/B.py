n=int(input())
b=[list(map(int,list(input()))) for _ in range(n)]
print(max(sum(sum(b[j][k]^b[i][k]^1 for k in range(n))==n for j in range(n)) for i in range(n)))