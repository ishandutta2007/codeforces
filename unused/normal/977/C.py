n,k=map(int,raw_input().split())
dat=map(int,raw_input().split())
dat.sort()
if k == n:
    print int(1e9)
elif k == 0:
    if dat[0] == 1:
        print -1
    else:
        print 1
elif dat[k] == dat[k-1]:
    print -1
else:
    print dat[k-1]