n,m=[int(k) for k in input().split(" ")]

s=[]
for k in range(n):
    s+=[input()+1000*"."]
s+=[500*"."]*500

areok=set()
isdone=False
isok=True
for i in range(n):
    for j in range(m):
        #print(i,j,s[i][j])
        if i>0 and s[i][j]=="*" and s[i-1][j]=="*" and j and s[i][j-1]=="*":
            #print("cand :",i,j)
            areok.add((i,j))
            isdone=True
            for w in [(1,0),(-1,0),(0,1),(0,-1)]:
                howmuch=1
                while s[i+w[0]*howmuch][j+w[1]*howmuch]=="*":
                    areok.add((i+w[0]*howmuch,j+w[1]*howmuch))
                    howmuch+=1
                if howmuch==1:
                    isok=False
                #print(w,howmuch)
            break
    if isdone:
        break

if not isdone:
    isok=False

if isok:
    for i in range(n):
        for j in range(m):
            if s[i][j]=="*" and (i,j) not in areok:
         #       print(i,j)
                isok=False


if isok:
    print("YES")
else:
    print("NO")