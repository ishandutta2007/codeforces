n=int(input())
s=input()
r=[0]*n
g=[0]*n
b=[0]*n
r[0]=(int(s[0]!="R"),None)
g[0]=(int(s[0]!="G"),None)
b[0]=(int(s[0]!="B"),None)
for i in range(1,n):
    if g[i-1][0]<b[i-1][0]:
        r[i]=(g[i-1][0]+int(s[i]!="R"),"G")
    else:
        r[i]=(b[i-1][0]+int(s[i]!="R"),"B")
    if r[i-1][0]<b[i-1][0]:
        g[i]=(r[i-1][0]+int(s[i]!="G"),"R")
    else:
        g[i]=(b[i-1][0]+int(s[i]!="G"),"B")
    if r[i-1][0]<g[i-1][0]:
        b[i]=(r[i-1][0]+int(s[i]!="B"),"R")
    else:
        b[i]=(g[i-1][0]+int(s[i]!="B"),"G")
x=min(r[-1][0],g[-1][0],b[-1][0])
print(x)
if r[-1][0]==x:
    out="R"
    curr="R"
elif g[-1][0]==x:
    out="G"
    curr="G"
else:
    out="B"
    curr="B"
for i in range(n-1,0,-1):
    if curr=="R":
        out+=r[i][1]
        curr=r[i][1]
    elif curr=="G":
        out+=g[i][1]
        curr=g[i][1]
    else:
        out+=b[i][1]
        curr=b[i][1]
print(out[::-1])