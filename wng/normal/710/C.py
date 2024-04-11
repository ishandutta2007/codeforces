# -*- coding: utf8 -*-

n=int(raw_input())

a=[[0 for i in range(n)] for j in range(n)]

#les diags sont impaires

for i in range(n):
    a[i][n/2]=1
    a[n/2][i]=1

nbi=2*n-1
i,j=0,0
while nbi<=(n*n)/2:
    j+=1
    if i==j:
        j+=1
    if j>=n/2:
        i+=1
        j=0
  #  print i,j
    nbi+=4
    a[i][j]=1
    a[i][n-1-j]=1
    a[n-1-i][j]=1
    a[n-1-i][n-1-j]=1

nbp=0
nbi2=0

for i in range(n):
    for j in range(n):
        if a[i][j]%2:
            a[i][j]+=2*nbi2
            nbi2+=1
        else:
            nbp+=1
            a[i][j]+=2*nbp


for i in range(n):
    print " ".join([ str(k) for k in a[i]])


##bon OK celui l marche pas parce que la diag est off (mon vieil algo semble
## ne generer qu'un carre semi magique
##k=0
##for i in range(n):
##    ii,jj=-2+i,0-i
##    for j in range(n):
##            k+=1
##            a[ii%n][jj%n]=k
##            #print k,i,j,(i+n/2)%n,(j+n/2)%n
##            ii+=1
##            jj+=1