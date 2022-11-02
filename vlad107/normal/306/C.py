import math
F=lambda x:math.factorial(x)
n,w,b=map(int,raw_input().split())
print (F(w)*F(b)*(w-1)*F(w+b-3)/F(n-3)/F(w+b-n))%1000000009