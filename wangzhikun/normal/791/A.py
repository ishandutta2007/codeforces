s = input()
a,b = s.split(' ')
a = int(a);b=int(b)
t=0
while a<=b:
    a=a*3
    b=b*2
    t+=1
print(t)