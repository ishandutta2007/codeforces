def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()

from fractions import gcd
    
n = int(input())    
a = n//2
b = n-a
while gcd(a,b) != 1:
  a -= 1
  b += 1
print(a,b)