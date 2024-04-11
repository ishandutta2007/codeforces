l=int(input())
n=input()

def solve(ind,d):
    global ans
    if ind<1 or ind>=l:
        return
    if n[ind]=='0':
        if d==0:
            return
        while 1<=ind<l and n[ind]=='0':
            ind+=d
    if ind<1 or ind>=l:
        return
    if n[ind]=='0':
        return
    res=int(n[:ind])+int(n[ind:])
    try:
        ans=min(ans,res)
    except:
        ans=res

inds=[]
for i in range(l//2-3,l//2+3):
    if 1<=i<l:
        inds+=[i]

for i in range(len(inds)):
    if i==0:
        d=-1
    elif i==len(inds)-1:
        d=1
    else:
        d=0
    solve(inds[i],d)

print(ans)