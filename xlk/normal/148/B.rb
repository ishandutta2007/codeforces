vp,vd,t,f,c=5.times.map{gets.to_r};z=0;
if vp<vd then d=vp*t*vd/(vd-vp)
	while(d<c)
		z+=1;d+=vp*(d/vd+f);d*=vd/(vd-vp)end end
p z