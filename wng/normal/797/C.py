s=raw_input()#"putainborderldemerdre"*10000#
t=""
u=""
n=len(s)

dp={}
for k in range(n):
    if s[k] not in dp:
        dp[s[k]]=[]
    dp[s[k]]+=[k]
corr=0

while len(s)>0:
    a=min(s)
    allas=[k-corr for k in dp[a] if k>=corr]
  #  print s,t,u,allas,a
    u+=a*len(allas)
    corr+=allas[-1]+1
    bf=0
    for k in range(len(allas)):
        t+=s[bf:allas[k]]
        bf=allas[k]+1
    s=s[allas[-1]+1:]
    if len(s)>0:
        a=min(s)
        while len(t)>0 and t[-1]<=a:
            u+=t[-1]
            t=t[:-1]
   # print s,t,u,allas,a
u+=t[::-1]
if len(u)!=n:
    print u
    1/0
print u