n,d=gets.split(" ").map {|x| x.to_i} 
cnt=0
i=0
raw=gets.split(" ").map {|x| x.to_i}
while(i<n)
  cnt+=raw[i]
  i+=1
end
l=cnt+(n-1)*10
if(l>d)
  puts "-1"
else
  print "#{2*(n-1)+(d-l)/5}"
end