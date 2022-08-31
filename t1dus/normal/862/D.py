from sys import *
n = int(input())
print("?","0"*n)
stdout.flush() 
cnt = int(input())
low = 1
high = n
one = zero = -1
while low <= high:
  mid = (low+high)//2
  s = "? "
  for i in range(1,n+1):
    if(low <= i <= mid): s += "1"
    else: s += "0"
  print(s)
  stdout.flush() 
  x = int(input())
  tot = mid-low+1
  if cnt-x == tot: #all ones
    # print("all ones",low,mid,high)
    one = low
    low = mid+1
  elif x-cnt == tot: #all zeros
    # print("all zeros",low,mid,high)
    zero = low
    low = mid+1
  else:
    high = mid
print("!",zero,one)    
stdout.flush()