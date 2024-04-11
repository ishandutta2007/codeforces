from sys import stdin
from fractions import gcd

def solve():
 cbrts={}
 for i in xrange(0, 1001):
     cbrts[i*i*i]=i
 n = int(stdin.readline().strip())
 answers=[0]*n
 for _ in xrange(n):
  a, b = map(int, stdin.readline().strip().split())
  _gcd=gcd(a, b)
  c=a//_gcd*b//_gcd
  if _gcd%c!=0:
   answers[_]='No'
   continue
  
  if not cbrts.has_key(_gcd//c):
   answers[_]='No'
  else:
   answers[_]='Yes'
 print "\n".join(answers)
   
solve()