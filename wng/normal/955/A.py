
hh,mm=[int(k) for k in raw_input().split(" ")]
h,d,c,n=[int(k) for k in raw_input().split(" ")]

#feed now

t=hh*60+mm

costnow=-((-h)/n) * c

t20=max(0,20*60-t)

cost20=-((-(h+t20*d))/n) * c *0.8

print min(costnow,cost20)