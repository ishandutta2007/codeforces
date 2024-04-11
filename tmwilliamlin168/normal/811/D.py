import sys
sys.setrecursionlimit(2*10**5)
n, m=map(int, input().split())
g=[input() for i in range(n)]
vis=[[0]*m for i in range(n)]
mp={}
l=[]
def dfs(i, j):
    vis[i][j]=1
    l.append((i, j))
    if g[i][j]=='F':
        return 1
    for d in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
        if not (i+d[0]<0 or i+d[0]>=n or j+d[1]<0 or j+d[1]>=m or g[i+d[0]][j+d[1]]=='*' or vis[i+d[0]][j+d[1]]) and dfs(i+d[0], j+d[1]):
            return 1
    l.pop()
    return 0
dfs(0, 0)
#print(l)
for i in range(1, len(l)):
    # i-1 to i
    d=(l[i][0]-l[i-1][0], l[i][1]-l[i-1][1])
    if not d in mp:
        if d[0]==0:
            print('R',flush=True)
            a,b=map(int, input().split())
            b-=1
            if b==l[i][1]:
                # actually right
                mp[(0, 1)]='R'
                mp[(0, -1)]='L'
                continue
            else:
                mp[(0, 1)]='L'
                mp[(0, -1)]='R'
        else:
            print('D',flush=True)
            a,b=map(int, input().split())
            a-=1
            if a==l[i][0]:
                # actually down
                mp[(1, 0)]='D'
                mp[(-1, 0)]='U'
                continue
            else:
                mp[(1, 0)]='U'
                mp[(-1, 0)]='D'
    print(mp[d],flush=True)
    input()