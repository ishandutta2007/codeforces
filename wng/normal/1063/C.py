n=[int(k) for k in raw_input().split(" ")][0]

from sys import stdout,exit

lstart=0
nbn=0

lim=10**9

print 0,lim
stdout.flush()
good=raw_input()
maxgood=-1
minbad=lim

def wheretolieu(where):
    return lim+min(0,where), lim-max(0,where)

nbn+=1
ta=2**(n-2)
where=0
before=False
while nbn!=n:
    wtl=wheretolieu(where)
    print wtl[0],wtl[1]
    stdout.flush()
    if ta:
        if (good==raw_input()):
            where+=ta
        else:
            where-=ta
    assert ta
    ta>>=1
    nbn+=1
"""
if (before):
    if where>0:
        print 0,0,wtl[0]-1,wtl[1]
    else:
        print 0,0,wtl[0]-1,wtl[1]-1
else:
    if where<0:
        print 0,0,wtl[0],wtl[1]-1
    else:
        print 0,0,wtl[0]-1,wtl[1]-1
"""
wtl=wheretolieu(where)
print 0,0,wtl[0],wtl[1]
stdout.flush()