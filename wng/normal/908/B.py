n,m=[int(k) for k in raw_input().split(" ")]

t=[0]*n
st=None
ex=None
for i in range(n):
    t[i]=raw_input()
    if "S" in t[i]:
        st=(i,[k for k in range(m) if t[i][k]=="S"][0])
    if "E" in t[i]:
        ex=(i,[k for k in range(m) if t[i][k]=="E"][0])

s=raw_input()

mvs=[(0,1),(0,-1),(1,0),(-1,0)]
import itertools

def isvalid(start,move):
    nc=(start[0]+move[0],start[1]+move[1])
    if nc[0]>=0 and nc[0]<n and nc[1]>=0 and nc[1]<m and t[nc[0]][nc[1]]!="#":
        if t[nc[0]][nc[1]]=="E":
            return 2
        else:
            return 1
    else:
        return 0
            
res=0
for p in itertools.permutations(range(4)):
    c=st
    isok=True
    done=False
    for j in s:
        mv=mvs[p[int(j)]]
        nm=isvalid(c,mv)
        if nm>0:
            if nm==2:
                done=True
                break
            c=(c[0]+mv[0],c[1]+mv[1])
        else:
            isok=True
            break
    if done:
        res+=1
print res