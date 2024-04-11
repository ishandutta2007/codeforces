#

x=int(raw_input())

h,m=[int(k) for k in raw_input().split(" ")]
i=0
while '7' not in str(h)+str(m):
    m-=x
    if m<0:
        m+=60
        h-=1
    if h<0:
        h+=24
    i+=1

print i