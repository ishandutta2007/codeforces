s=raw_input()
dc={}
dm={}
n=len(s)
for k in range(n):
    l=s[k]
    if l not in dc:
        dm[l]=k+1
    else:
        dm[l]=max(dm[l],k-dc[l])
    dc[l]=k
  #  print l, dm, dc
for k in dm.keys():
    dm[k]=max(dm[k],n-dc[k])

print min(dm.values())