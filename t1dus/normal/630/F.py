from math import factorial as f
def ncr(n,r):
  return f(n)//(f(r)*f(n-r))
x = int(input())
print(ncr(x,5)+ncr(x,6)+ncr(x,7))