inp = map(int, raw_input().split())
x = inp[0]
y = inp[1]
#print x + y

aa = 1
ao = 0
ba = 0
bo = 1
res = ""

def Cross(x1, y1, x2, y2):
  return x1 * y2 - y1 * x2 

MIL = 10
MIL = 1000000000000000000

def Iter():
  global aa
  global ba
  global ao
  global bo
  global res
  #print "xy",x,y
  ca = aa + ba
  co = ao + bo
  #print aa,ao,ba,bo
  if Cross(ca, co, x, y) <= 0:
    kl = 1
    kp = MIL
    faj = 1
    while kl <= kp:
      aktc = (kl + kp) / 2
      #print aktc
      ca = ba + aa * aktc
      co = bo + ao * aktc
      if Cross(ca, co, x, y) < 0:
        #print ca,co,x,y
        faj = aktc
        kl = aktc + 1
      else:
        kp = aktc - 1
    res += str(faj)
    res += 'A'
    ba += aa * faj
    bo += ao * faj
  else:
    kl = 1
    kp = MIL
    faj = 1
    while kl <= kp:
      aktc = (kl + kp) / 2
      #print aktc
      ca = aa + ba * aktc
      co = ao + bo * aktc
      if Cross(ca, co, x, y) > 0:
        faj = aktc
        kl = aktc + 1
      else:
        kp = aktc - 1
    res += str(faj)
    res += 'B'
    aa += ba * faj
    ao += bo * faj
  
  
while aa + ba < x or ao + bo < y:
  Iter()
  #print aa,ao,ba,bo,res
  
if aa + ba == x and ao + bo == y:
  print res
else:
  print "Impossible"