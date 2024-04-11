n=int(input())-1
s=input()
mx={}
c={}
for i in range(n):
    if not s[2*i] in c:
        c[s[2*i]]=0
        mx[s[2*i]]=0
    c[s[2*i]]-=1
    if not s[2*i+1].lower() in c:
        c[s[2*i+1].lower()]=0
        mx[s[2*i+1].lower()]=0
    c[s[2*i+1].lower()]+=1
    mx[s[2*i+1].lower()]=max(mx[s[2*i+1].lower()], c[s[2*i+1].lower()])
ans=0
for k in mx:
    ans+=mx[k]
print(ans)