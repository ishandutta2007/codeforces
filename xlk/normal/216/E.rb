a=Hash.new 0;a[0]=1;k,b,n=gets.split.map &:to_i;s=t=c=z=0;k-=1
(gets.split.map &:to_i).each{|i|s=(s+i)%k;z+=a[(s-b)%k];a[s]+=1;if i>0 then c=0;else t+=c+=1 end}
if b==0 then z=t elsif b==k then z-=t end;p z