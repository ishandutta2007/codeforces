n,k = map(int,input().split())
n*=2
n+=2
l,le,e = [[] for i in range(n)],[[] for i in range(n)],[0]*n
ok = 1
for i in range(k):
 a,c,b = input().split()
 a,b = int(a), int(b)
 if c=="=":
  if a==b:
   continue
  if (e[a] and e[a]!=b) or (e[b] and e[b]!=a):
   ok = 0
  e[a], e[b] = b,a
 if c=="<":
  a,b,c = b,a,">"
 if c==">":
  l[a].append(b)
 if c=="<=":
  a,b,c = b,a,">="
 if c==">=":
  le[a].append(b)

def check(i, j, a, b):
 if e[a] and e[a]!=a and e[a]!=b:
  return 0
 for x in l[a]:
  if x>i and x<j:
   return 0
 for x in le[a]:
  if x>i and x<j and x!=a and x!=b:
   return 0
 return 1

dp = [[0]*n for i in range(n)]
dp[0][n-1] = 1
ans = 0
for i in range(n):
 for j in range(n-1,i,-1):
  if i+1==j:
   ans+=dp[i][j]
  elif ((i+j)%2)==1:
   if check(i,j,i+1,i+2) and check(i,j,i+2,i+1):
    dp[i+2][j]+=dp[i][j]
   if i+3<j and check(i,j,j-2,j-1) and check(i,j,j-1,j-2):
    dp[i][j-2]+=dp[i][j]
   if i+3<j and check(i,j,i+1,j-1) and check(i,j,j-1,i+1):
    dp[i+1][j-1]+=dp[i][j]

print(ans if ok else 0)