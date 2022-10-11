from math import sqrt

def valid(n):
  x = int(sqrt(n))
  return x*x == n and prime(x)

prime = [True] * 1000001
i = 3
while i < len(prime):
  if prime[i]:
    j = i * i
    while j < len(prime):
      prime[j] = False
      j += i
  i += 2
primes = set()
primes.add(2)
i = 3
while i < len(prime):
  if prime[i]:
    primes.add(i)
  i += 2
  
qq = int(raw_input())
line = raw_input()
qqqq = line.split()
for qqq in qqqq:
  n = int(qqq)
  x = int(sqrt(n))
  if x * x != n:
    print "NO"
  else:
    if x in primes:
      print "YES"
    else:
      print "NO"