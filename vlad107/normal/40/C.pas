{$r-,q-,s-,i-,o+}
uses
  math;
  
var
  found:boolean;
  t,ss,ff,i,tmp,n,m,x,y:longint;
  res,v:qword;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(x,n,y,m);
  if (n=m)then begin
    Writeln(max(x,y)+1);
    exit;
  end;
  if (n>m)then begin
    tmp:=n;n:=m;m:=tmp;
    tmp:=x;x:=y;y:=tmp;
  end;
  if (n+x<m-y)
    then writeln(x+y+1)
    else begin
      v:=0;
      res:=0;
      for i:=1 to x do begin
        found:=false;
        t:=m-n-i;
        if (t>=1)and(t<=y)then inc(v);
        if (t>=1)and(t<=y)then found:=true;
        t:=m-n+i;
        if (t>=1)and(t<=y)then inc(v);
        if (t>=1)and(t<=y)then found:=true;
        t:=n-m+i;
        if (t>=1)and(t<=y)then inc(v);
        if (t>=1)and(t<=y)then found:=true;
		ss:=m-n-i+1;
		if (n+i-m+1>ss)then ss:=n+i-m+1;
		if (1>ss)then ss:=1;
		ff:=y;
		if (m-n+i-1<ff)then ff:=m-n+i-1;
		if (ff>=ss)then inc(v,2*(ff-ss+1))else inc(res,ord(not found));
      end;
      for i:=1 to y do begin
        found:=false;
        t:=m-n-i;
        if (t>=1)and(t<=x)then found:=true;
        t:=n-m+i;
        if (t>=1)and(t<=x)then found:=true;
        ss:=m-n-i+1;
        if (n-m+i+1>ss)then ss:=n-m+i+1;
        if (1>ss)then ss:=1;
        ff:=x;
        if (m-n+i-1<ff)then ff:=m-n+i-1;
        if (ff<ss)then inc(res,ord(not found));
      end;
      writeln(res+v+2);
    end;
  close(output);close(input);
end.