{$r-,q-,s-,i-,o+}
const
  bhash=10000019;
var
  t:array[0..100500,1..4]of longint;
  pred:array[0..100500]of longint;
  g:array[0..100500]of int64;
  last:array[0..bhash+10]of longint;
  a:array[1..4]of longint;
  kg,q,n,min,i,kt,o,j:longint;
  xx:int64;
  s:ansistring;
  res:array[1..4]of boolean; 
  function fhash(x:int64):longint;
    var
      ii:longint;
    begin
      ii:=last[x mod bhash];
      while (ii>0)do begin
        if (g[ii]=x)then begin
          fhash:=1;
	  exit;
	end;
        ii:=pred[ii];
      end;
      fhash:=-1;
    end;
begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  readln(n);
  readln(s);
  i:=0;
  kt:=1;
  kg:=0;
  fillchar(t,sizeof(t),$0);
  fillchar(res,sizeof(res),false);
  while (i<kt)do begin
    inc(i);
    for j:=1 to 4 do a[j]:=t[i][j];
    o:=t[i][1]+t[i][2]+t[i][3]+t[i][4]+1;
    if (o=n+1)then begin
      min:=a[1];
      for j:=2 to 4 do 
        if (a[j]<min)then min:=a[j];
      for j:=1 to 4 do 
        if (a[j]=min)then res[j]:=true;
      continue;
    end;
    if (s[o]='G')then inc(a[1])else
    if (s[o]='H')then inc(a[2])else 
    if (s[o]='R')then inc(a[3])else
    if (s[o]='S')then inc(a[4])else begin
      min:=a[1];
      for j:=2 to 4 do 
        if (a[j]<min)then min:=a[j];
      for j:=1 to 4 do 
        if (a[j]=min)then begin
	  inc(a[j]);
	  xx:=a[1]*10000;
	  xx:=(xx+a[2])*10000;
	  xx:=(xx+a[3])*10000;
	  xx:=xx+a[4];
	  if (fhash(xx)<0)then begin
            inc(kg);
	    g[kg]:=xx;
	    pred[kg]:=last[xx mod bhash];
	    last[xx mod bhash]:=kg;
	    inc(kt);
	    t[kt][1]:=a[1];t[kt][2]:=a[2];t[kt][3]:=a[3];t[kt][4]:=a[4];
	  end;
	  dec(a[j]);
	end;
      continue;
    end;
    xx:=a[1]*10000;
    xx:=(xx+a[2])*10000;
    xx:=(xx+a[3])*10000;
    xx:=xx+a[4];
    if (fhash(xx)<0)then begin
      inc(kg);
      g[kg]:=xx;
      pred[kg]:=last[xx mod bhash];
      last[xx mod bhash]:=kg;
      inc(kt);
      t[kt][1]:=a[1];t[kt][2]:=a[2];t[kt][3]:=a[3];t[kt][4]:=a[4];
    end;
  end;
  if (res[1])then writeln('Gryffindor');
  if (res[2])then writeln('Hufflepuff');
  if (res[3])then writeln('Ravenclaw');
  if (res[4])then writeln('Slytherin');
end.