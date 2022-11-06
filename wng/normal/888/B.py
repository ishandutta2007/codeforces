n=int(raw_input())
a=raw_input()
dc={}
dc["L"]=0
dc["D"]=0
dc["U"]=0
dc["R"]=0
for l in a:
    dc[l]+=1

print 2*min(dc["L"],dc["R"])+2*min(dc["U"],dc["D"])