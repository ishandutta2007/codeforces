var
  ss,ff,nn:array[1..100000] of longint;
  kg,x,tmp,n,l,s,f,i,k,j,q:longint;
  

  procedure swap(k,x:longint);
    begin
      tmp:=ss[k];ss[k]:=ss[x];ss[x]:=tmp;
      tmp:=ff[k];ff[k]:=ff[x];ff[x]:=tmp;
      tmp:=nn[k];nn[k]:=nn[x];nn[x]:=tmp;
    end;

  procedure add(x,nom:longint);
    var
      i:longint;

    begin
      for i:=1 to kg-1 do
        if (ss[i+1]-ff[i]>=s+f+x)then begin
          inc(kg);
          ss[kg]:=ff[i]+s;
          ff[kg]:=ff[i]+s+x;
          nn[kg]:=nom;
          writeln(ss[kg]);
          exit;
        end;
      writeln(-1);
    end;

  procedure del(x:longint);
    var
      i:longint;

    begin
      for i:=1 to kg do 
        if (nn[i]=x)then begin
          swap(i,kg);
          dec(kg);
          exit;
        end;
    end;
                 
begin
  read(l,s,f,n);
  kg:=2;
  ss[1]:=-s-1;ff[1]:=-s;
  ss[2]:=l+f;ff[2]:=l+f+1;
  for i:=1 to n do begin
    read(q,x);
    case (q) of
      1:add(x,i);
      2:del(x);
    end;
    for j:=1 to kg-1 do 
      for k:=1 to kg-1 do 
        if (ss[k]>ss[k+1])then swap(k,k+1);
  end;
end.