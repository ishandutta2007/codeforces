{$r-,q-,s-,i-,o+}
uses
  math;

const
  MAXY=1000007;
  MAXN=1000000;
    
type
  TTree=record
    x,y,max,nom,left,right,size:longint;
  end;
  
var
  tr:array[0..MAXN]of TTree;
  used:array[0..MAXY]of boolean;
  lr,rr,nr,x,c,nom,kt,root,i,tt:longint;

  function genrandom:longint;
    var
      y:longint;
      
    begin
      y:=random(MAXY);
      while (used[y])do y:=random(MAXY);
      genrandom:=y;
    end;

  function build(x,nom,y:longint):longint;
    begin
      inc(kt);
      tr[kt].x:=x;
      tr[kt].nom:=nom;
      tr[kt].y:=y;
      tr[kt].max:=x;
      tr[kt].left:=0;
      tr[kt].right:=0;
      tr[kt].size:=1;
      build:=kt;
    end;
    
  procedure update(x:longint);
    var
      left,right:longint;
      
    begin
      left:=tr[x].left;
      right:=tr[x].right;
      tr[x].size:=tr[left].size+tr[right].size+1;
      tr[x].max:=max(tr[left].max,tr[right].max);
      if (tr[x].x>tr[x].max)then tr[x].max:=tr[x].x;
    end;
    
  procedure split(t,x:longint;var lr,rr:longint);
    var
      left,right:longint;
      
    begin
      if (t=0)then begin lr:=0;rr:=0;exit end;
      left:=tr[t].left;
      right:=tr[t].right;
      if (x<=tr[left].size)then begin
        split(left,x,lr,rr);
        tr[t].left:=rr;
        update(t);
        rr:=t;
      end else begin
        split(right,x-tr[left].size-1,lr,rr);
        tr[t].right:=lr;
        update(t);
        lr:=t;
      end;
    end;
    
  function merge(lr,rr:longint):longint;
    begin
      if (lr=0)then begin merge:=rr;exit end;
      if (rr=0)then begin merge:=lr;exit end;
      
      if (tr[lr].y>tr[rr].y)then begin
        tr[lr].right:=merge(tr[lr].right,rr);
        update(lr);
        merge:=lr;
      end else begin
        tr[rr].left:=merge(lr,tr[rr].left);
        update(rr);
        merge:=rr;
      end;
    end;

  function find(x,t:longint):longint;
    var
      left,right:longint;
      
    begin
      if (x=0)then begin
        find:=0;
        exit;
      end;
      left:=tr[x].left;
      right:=tr[x].right;
      if (right<>0)and(tr[right].max>t)then find:=tr[left].size+1+find(right,t)else
      if (tr[x].x>t)then find:=tr[left].size+1 else
      find:=find(left,t);
    end;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  fillchar(used,sizeof(used),false);
  kt:=0;
  root:=0;
  read(tt);
  for i:=1 to tt do begin
    read(x,c);
    nr:=build(x,i,genrandom);
    nom:=find(root,x);
    if (i-1-c>nom)then nom:=i-1-c;
    if (0>nom)then nom:=0;
    split(root,nom,lr,rr);
    root:=merge(lr,nr);
    root:=merge(root,rr);
  end;
  for i:=1 to tt do begin
    split(root,1,lr,rr);
    write(tr[lr].nom,' ');
    root:=rr;
  end;
  writeln;
  close(output);close(input);
end.