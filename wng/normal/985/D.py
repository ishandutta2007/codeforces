n,h=[int(k) for k in raw_input().split(" ")]

#

if h*(h+1)/2>=n: #result is highest k k(k+1)/2<=min(n,h)
    k=0
    kk=1<<30
    while kk:
        tt=k+kk
        if tt*(tt+1)/2<n:
            k+=kk
        kk>>=1
    print k+1
else:
    #Avec une largeur de k>=h je peux faire  k*(k+1)/2  + (k*(k-1)/2 - h(h-1)/2)
    k=h
    kk=1<<30
    while kk:
        tt=k+kk
        mh=(tt+h)/2;
        nbs=mh*(mh+1)/2  +  (mh*(mh-1)/2 - h*(h-1)/2) + (mh if not (tt+h-1)%2 else 0)
        if nbs<n:
            k+=kk
        kk>>=1
    print k+1
 #   tobuild= (left-1) / h + 1