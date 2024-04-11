for s in[*open(0)][1:]:
 n=int(s);r=0
 while n%3<1:r+=n%2+1;n//=6-n%6
 print([r,-1][n>1])