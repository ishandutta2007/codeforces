s=input()
x=int(input())
 
if s.lower()=="agc" and x>=1200:
  print("YES")
elif s.lower()=="arc" and x<2800:
  print("YES")
elif s.lower()=="abc" and x<2000:
  print("YES")
else:
  print("NO")