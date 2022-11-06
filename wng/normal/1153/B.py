
n,m,h=[int(k) for k in input().split(" ")]

cols=[int(k) for k in input().split(" ")]
rows=[int(k) for k in input().split(" ")]
mat=[]
res=[[0 for j in range(m)] for i in range(n)]
for i in range(n):
    mat+=[[int(k) for k in input().split(" ")]]

for i in range(n):
    for j in range(m):
        res[i][j]=str(mat[i][j]*min(cols[j],rows[i]))
    print(" ".join(res[i]))