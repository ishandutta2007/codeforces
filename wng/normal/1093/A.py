t=[int(k) for k in raw_input().split(" ")][0]
for i in range(t):
    n=[int(k) for k in raw_input().split(" ")][0]
    nbj=1
    while 2*nbj<=n:
        left=n-2*nbj
        if left<=5*nbj:
            print nbj
            break
        nbj+=1