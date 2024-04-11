n=int(raw_input())
cur=2
for i in range(1,n+1):
  tg=i*(i+1)*i*(i+1)
  print (tg-cur)/i
  cur=i*(i+1)