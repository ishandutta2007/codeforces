{$macro+}
{$define free}

const
  u='U';
  d='D';
  l='L';
  r='R';
  p='.';
  f='F';
  s='*';

var
  n,m,i,j,x,y,fx,fy,ud,lr,head,tail:longint;
  a:array[1..100,1..100]of char;
  nu,nd,nl,nr:char;
  qx,qy,qp:array[1..10000]of longint;
  v:array[1..100,1..100]of boolean;

procedure print(c:char);{$ifdef free}overload;{$endif}
begin
  writeln(c);
  flush(output);
  readln(x,y);
  if (x=-1)or((x=fx)and(y=fy))
    then halt
end;

procedure print(t:longint);{$ifdef free}overload;{$endif}
var
  p:longint;
begin
  p:=qp[t];
  if p<>0 then
    case qx[t]-qx[p] of
      1:
        begin
          print(p);
          print(nd)
        end;
      -1:
        begin
          print(p);
          print(nu)
        end;
      else
        case qy[t]-qy[p] of
          1:
            begin
              print(p);
              print(nr)
            end;
          -1:
            begin
              print(p);
              print(nl)
            end
        end
    end
end;

procedure add(x,y:longint);
begin
  if v[x,y] then
    exit;
  qx[tail]:=x;
  qy[tail]:=y;
  qp[tail]:=head;
  v[x,y]:=true;
  if (x=fx)and(y=fy) then
    print(tail);
  inc(tail)
end;

begin
  readln(n,m);
  for x:=1 to n do
    begin
      for y:=1 to m do
        begin
          read(a[x,y]);
          if a[x,y]=f then
            begin
              fx:=x;
              fy:=y
            end
        end;
      readln
    end;
  if n=1 then
    begin
      for i:=1 to m-1 do
        print(l);
      for i:=1 to m-1 do
        print(r)
    end;
  if m=1 then
    begin
      for i:=1 to n-1 do
        print(u);
      for i:=1 to n-1 do
        print(d)
    end;
  x:=1;
  y:=1;
  ud:=-1;
  lr:=-1;
  if a[2,1]<>s
    then
      begin
        print(d);
        if x=2
          then ud:=0
          else ud:=1;
        if (ud=0)and(a[1,2]<>s)
          then
            begin
              print(u);
              print(r);
              if y=2
                then lr:=0
                else lr:=1
            end
          else
            begin
              while a[x,2]=s do
                if ud=0
                  then print(d)
                  else print(u);
              print(r);
              if y=2
                then lr:=0
                else lr:=1
            end
      end
    else
      begin
        print(r);
        if y=2
          then lr:=0
          else lr:=1;
              while a[2,y]=s do
                if lr=0
                  then print(r)
                  else print(l);
              print(d);
              if x=2
                then ud:=0
                else ud:=1
      end;
  if ud=1
    then
      begin
        nu:=d;
        nd:=u
      end
    else
      begin
        nu:=u;
        nd:=d
      end;
  if lr=1
    then
      begin
        nl:=r;
        nr:=l
      end
    else
      begin
        nl:=l;
        nr:=r
      end;
{$ifdef free}
  fillchar(v,sizeof(v),0);
{$endif}
  v[x,y]:=true;
  qx[1]:=x;
  qy[1]:=y;
  qp[1]:=0;
  head:=1;
  tail:=2;
  repeat
    if (qx[head]>1)and(a[qx[head]-1,qy[head]]<>s) then
      add(qx[head]-1,qy[head]);
    if (qx[head]<n)and(a[qx[head]+1,qy[head]]<>s) then
      add(qx[head]+1,qy[head]);
    if (qy[head]>1)and(a[qx[head],qy[head]-1]<>s) then
      add(qx[head],qy[head]-1);
    if (qy[head]<m)and(a[qx[head],qy[head]+1]<>s) then
      add(qx[head],qy[head]+1);
    inc(head)
  until false
end.