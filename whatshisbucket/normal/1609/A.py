for s in[*open(0)][2::2]:
 *a,=map(int,s.split());c=1
 for x in a:b=x&-x;a[a.index(x)]//=b;c*=b
 print(sum(a)+max(a)*(c-1))